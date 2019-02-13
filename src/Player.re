open Graphics;
open Draw;


type t = {
  graphic: Graphics.t(t),
  mutable position: Point.t,
};

let make = () => {
  open Point;

  let show = (ctx, self) => {
    circle(~r=5.0, ~point=self.position, ctx);
  };

  let update = (ctx, self) => {
    self.position = vector2(0.5, 0.5) + self.position;

    circle(~r=5.0, ~point=self.position, ctx);
  };

  let plGraphic = makeGraphic(~show=Some(show), ~update=Some(update), ());

  {graphic: plGraphic, position: vector2(0.0, 0.0)};
};
