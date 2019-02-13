open Webapi.Canvas;


type boundaries = {
  width: float,
  height: float,
};

type t = {
  boundaries,
  mutable origin: Point.t,
  ctx: Canvas2d.t,
};

let create =
    (~boundaries, ~origin=Point.vector2(0.0, 0.0), ctx) => {
  boundaries,
  origin,
  ctx,
};

let viewBoundaryWidth = world => world.boundaries.width;

let render = (world: t, callback: t => unit) => {
  let rec loop = _t => {
    Canvas.clear(
      ~w=world.boundaries.width,
      ~h=world.boundaries.height,
      world.ctx,
    );

    callback(world);
    Webapi.requestAnimationFrame(loop);
  };

  Webapi.requestAnimationFrame(loop);
};
