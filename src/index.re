open Webapi.Dom;
open Webapi.Canvas.CanvasElement;

let main = () => {
  let canvas =
    Belt.Option.(document |> Document.getElementById("app") |> getExn);
  let ctx = getContext2d(canvas);
  let p1 = ref(Point.vector2(0.0, 0.0));
  let velocity = Point.vector2(0.2, -0.2);
  let newBase = (Point.vector2(1.0, 0.0), Point.vector2(0.0, 1.0));
  let newOrigin = Point.vector2(50.0, 50.0);

  newBase->Canvas.baseMove(ctx);
  newOrigin->Canvas.originMove(ctx);

  let rec loop = _e => {
    p1 := Point.add(p1^, velocity);
    ctx |> Canvas.clear(~h=400.0, ~w=400.0, ~point=Point.negative(newOrigin));
    ctx |> Draw.circle(~point=p1^, ~r=2.0);
    loop |> Webapi.requestAnimationFrame;
  };

  loop |> Webapi.requestAnimationFrame;
};

main();
