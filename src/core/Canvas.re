open Webapi.Canvas;
open Point;

external context2dToJsObj: Canvas2d.t => Js.t({..}) = "%identity";

[@bs.set] external setWidth: (Dom.element, int) => unit = "width";
[@bs.set] external setHeight: (Dom.element, int) => unit = "height";

let setSize = (~w: int, ~h: int, canvas) => {
  setHeight(canvas, h);
  setWidth(canvas, w);
};

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

let clear = (~point=vector2(0.0, 0.0), ~w, ~h, ctx) => {
  let {x, y} = point;

  Canvas2d.clearRect(~x, ~y, ~w, ~h, ctx);
};