open Webapi.Dom;
open Webapi.Canvas.CanvasElement;
open Utils;


let main = () => {
  let canvas =
    document
    |> Document.getElementById("app")
    |> unwrap;
  let ctx = getContext2d(canvas);
  let renderer = Draw.make(ctx);
  let p1 = ref(Point.vector2(0.1, 0.1));

  let rec loop = _e => {
    p1 := Point.add(p1^, Point.vector2(0.1, 0.1));

    renderer.clear(~h=400.0, ~w=400.0, ());
    renderer.circle(~point=p1^, ~r=10.0, ());
    Webapi.requestAnimationFrame(loop);
  };

  Webapi.requestAnimationFrame(loop);
};

main();
