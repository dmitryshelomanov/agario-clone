open Webapi.Dom;
open Webapi.Canvas.CanvasElement;
open Point;
open Draw;
open Utils;


let main = () => {
  let canvas =
    document
    |> Document.getElementById("app")
    |> unwrap;
  let ctx = getContext2d(canvas);
  let p1 = ref(vector2(0.1, 0.1));

  distance(vector2(0.0, 0.0), vector2(10.0, 10.0)) |> Js.log;

  let rec loop = _e => {
    p1 := add(p1^, vector2(0.1, 0.1));

    clear(~h=400.0, ~w=400.0, ctx);
    circle(~point=p1^, ~r=10.0, ctx);
    Webapi.requestAnimationFrame(loop);
  };

  Webapi.requestAnimationFrame(loop);
};

main();
