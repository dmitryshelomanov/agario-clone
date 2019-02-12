open Webapi.Dom;
open Webapi.Canvas.CanvasElement;
open Point;
open App;
open Draw;
open Collision;

let tick = world => {
  world
  |> viewPopulation
  |> Js_array.forEach(shape =>
       switch (shape) {
       | Circle(circle) =>
         if (outOfBoundaries(Left(circle.point.x), 0.0)
             || outOfBoundaries(
                  Right(circle.point.x),
                  viewBoundaryWidth(world),
                )) {
           circle.velocity =
             vector2(negative(circle.velocity).x, circle.velocity.y);
         };
         circle.point = add(circle.velocity, circle.point);
       }
     );
};

let main = () => {
  let canvas =
    Belt.Option.(document |> Document.getElementById("app") |> getExn);

  let ctx = getContext2d(canvas);

  let world =
    create(
      ~boundaries={width: 400.0, height: 400.0},
      ~population=[|
        makeCircle(
          ~r=20.0,
          ~point=vector2(10.0, 10.0),
          ~velocity=vector2(3.0, 0.0),
          (),
        ),
        makeCircle(~r=5.0, ~point=vector2(100.0, 100.0), ()),
      |],
      ctx,
    );

  render(world, tick);
};

main();
