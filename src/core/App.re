open Webapi.Canvas;
open Draw;

type boundaries = {
  width: float,
  height: float,
};

type t = {
  boundaries,
  mutable origin: Point.t,
  ctx: Canvas2d.t,
  mutable population: array(shape),
};

let create =
    (~boundaries, ~origin=Point.vector2(0.0, 0.0), ~population=[||], ctx) => {
  boundaries,
  origin,
  ctx,
  population,
};

let viewPopulation = world => world.population;
let viewBoundaryWidth = world => world.boundaries.width;

let render = (world: t, callback: t => unit) => {
  let localDraw = shape => draw(shape, world.ctx);

  let rec loop = _t => {
    Canvas.clear(
      ~w=world.boundaries.width,
      ~h=world.boundaries.height,
      world.ctx,
    );
    world.population |> Js_array.forEach(localDraw);
    callback(world);
    Webapi.requestAnimationFrame(loop);
  };

  Webapi.requestAnimationFrame(loop);
};
