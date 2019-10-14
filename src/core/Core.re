open Webapi.Canvas;
open Webapi.Canvas.CanvasElement;
open Webapi.Dom;

type inputs = {
  mouse: Inputs.Mouse.t,
  keyboard: Inputs.Keyboard.t,
};

type t = {
  boundaries: Size.t,
  screenSizes: Size.t,
  context: Canvas2d.t,
  camera: Camera.t,
  inputs,
};

let mountCanvas = canvas => {
  let _ =
    Option.(
      document
      |> Document.asHtmlDocument
      |> andThen(HtmlDocument.body)
      |> map(Element.appendChild(canvas))
    );
  ();
};

let createCanvasWithContext = ((w, h)) => {
  let canvas = document |> Document.createElement("canvas");
  let ctx = getContext2d(canvas);

  canvas |> Canvas.setSize(~w, ~h);

  (canvas, ctx);
};

let makeEngine =
    (
      ~screenSizes,
      ~boundaries,
      ~initialCameraPosition=Point.vector2(0.0, 0.0),
      ~offset,
      (),
    ) => {
  let (canvas, context) = createCanvasWithContext(screenSizes);
  let camera =
    Camera.make(
      ~size=screenSizes,
      ~offset,
      ~position=initialCameraPosition,
      (),
    );
  let inputs = {
    mouse: Inputs.Mouse.createMouseControll(canvas),
    keyboard: Inputs.Keyboard.makeKeyBoardControll(),
  };

  mountCanvas(canvas);

  {boundaries, screenSizes, context, camera, inputs};
};

let looper = (~game: t, callback: float => unit) => {
  let lastFrame = ref(0.0);
  let {screenSizes, context} = game;
  let (width, height) = screenSizes;

  let rec loop = timestamp => {
    Canvas.clear(~w=width, ~h=height, context);

    callback(timestamp -. lastFrame^);
    lastFrame := timestamp;
    Webapi.requestAnimationFrame(loop);
  };

  Webapi.requestAnimationFrame(loop);
};