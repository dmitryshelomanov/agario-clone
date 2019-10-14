type angle = float;

type rect = {
  mutable position: Point.t,
  mutable size: Size.t,
  mutable angle: float,
  mutable color: string,
};

type t =
  | Rect(rect);

let id = (arg: 'a) => arg;

let makeRect =
    (~position: Point.t, ~size: Size.t, ~angle=0.0, ~color="black", ()) =>
  Rect({position, size, angle, color});

let render = (~pointTransformer=id, (ctx, shape)) =>
  switch (shape) {
  | Rect({size, position, angle, color}) =>
    ctx
    |> Draw.rect(~point=pointTransformer(position), ~angle, ~size, ~color)
  };

let size = shape =>
  switch (shape) {
  | Rect({size}) => size
  };

let position = (shape): Point.t =>
  switch (shape) {
  | Rect({position}) => position
  };

let setPosition = (shape, position) =>
  switch (shape) {
  | Rect(rect) => rect.position = position
  };