open Webapi.Dom;
open Webapi.Canvas.CanvasElement;
open Point;
open Collision;

let main = () => {
  let canvas =
    Belt.Option.(document |> Document.getElementById("app") |> getExn);
  let ctx = getContext2d(canvas);
  let p1 = ref(vector2(5.0, 5.0));
  let velocity = ref(vector2(2.0, 5.0));
  let worldMaxSize = 400.0;

  let rec loop = _e => {
    if (outOfBoundaries(Right(worldMaxSize), p1^.x)
        || outOfBoundaries(Left(0.0), p1^.x)) {
      velocity := vector2(negative(velocity^).x, velocity^.y);
    };

    if (outOfBoundaries(Right(worldMaxSize), p1^.y)
        || outOfBoundaries(Left(0.0), p1^.y)) {
      velocity := vector2(velocity^.y, negative(velocity^).y);
    };

    p1 := add(p1^, velocity^);
    ctx |> Canvas.clear(~h=worldMaxSize, ~w=worldMaxSize);
    ctx |> Draw.circle(~point=p1^, ~r=2.0);
    Webapi.requestAnimationFrame(loop);
  };

  Webapi.requestAnimationFrame(loop);
};

main();
