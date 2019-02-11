open Webapi.Canvas;
open Point;

let baseMove = (matrix: (Point.t, Point.t), ctx) => {
  let (i, j) = matrix;

  Canvas2d.transform(
    ~m11=i.x,
    ~m12=j.x,
    ~m21=i.y,
    ~m22=j.y,
    ~dx=0.0,
    ~dy=0.0,
    ctx,
  );
};

let originMove = (origin: Point.t, ctx) =>
  Canvas2d.translate(~x=origin.x, ~y=origin.y, ctx);

let clear = (~point=Point.vector2(0.0, 0.0), ~w, ~h, ctx) => {
  let {x, y} = point;

  Canvas2d.clearRect(~x, ~y, ~w, ~h, ctx);
};
