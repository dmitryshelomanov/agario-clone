open Webapi.Canvas.Canvas2d;
open Point;

let circle = (~point, ~r, ~color="black", ctx) => {
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
};

let clear = (~x=0.0, ~y=0.0, ~w, ~h, ctx) => clearRect(~x, ~y, ~w, ~h, ctx);
