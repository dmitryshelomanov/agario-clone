open Webapi.Canvas.Canvas2d;
open Point;

type circle = {
  mutable point: Point.t,
  mutable radius: float,
  mutable color: string,
  mutable velocity: Point.t,
};

type shape =
  | Circle(circle);

let makeCircle = (~point, ~r, ~color="black", ~velocity=vector2(0.0, 0.0), ()) =>
  Circle({point, radius: r, color, velocity});

let draw = (shape, ctx) =>
  switch (shape) {
  | Circle(circle) =>
    let {point, radius, color} = circle;
    let {x, y} = point;

    beginPath(ctx);
    arc(
      ~x,
      ~y,
      ~r=radius,
      ~startAngle=0.0,
      ~endAngle=Js.Math._PI *. 2.0,
      ~anticw=false,
      ctx,
    );
    setFillStyle(ctx, String, color);
    fill(ctx);
  };
