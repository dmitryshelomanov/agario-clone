open Webapi.Canvas.Canvas2d;
open Point;

type t = {
  circle: (~point: Point.t, ~r: float, ~color: string=?, unit) => unit,
  clear: (~x: float=?, ~y: float=?, ~w: float, ~h: float, unit) => unit,
};

let make = ctx => {
  circle: (~point, ~r, ~color="black", ()) => {
    let {x, y} = point;

    beginPath(ctx);
    arc(
      ~x,
      ~y,
      ~r,
      ~startAngle=0.0,
      ~endAngle=Js.Math._PI *. 2.0,
      ~anticw=false,
      ctx,
    );
    setFillStyle(ctx, String, color);
    fill(ctx);
  },

  clear: (~x=0.0, ~y=0.0, ~w, ~h, ()) => clearRect(~x, ~y, ~w, ~h, ctx),
};
