open Webapi.Dom;
open Webapi.Canvas.CanvasElement;

let main = () => {
  let canvas =
    Belt.Option.(document |> Document.getElementById("app") |> getExn);

  Canvas.setSize(~w=600, ~h=300, canvas);

  let vertexes = [|Point.vector2(50.0, 50.0), Point.vector2(100.0, 100.0)|];
  let ctx = getContext2d(canvas);
  let camera = Camera.createCamera(ctx);
  let mouse = Mouse.createMouseControll(canvas);

  ctx
  |> App.looper(() => {
       let mousePos = Mouse.getPosition(mouse);
       vertexes
       |> Js_array.forEach(point =>
            Draw.circle(
              ~point=
                Camera.computedNextPositionByCamera(
                  ~point,
                  ~coord=Camera.GLOBAL_COORD,
                  camera,
                ),
              ~r=25.0,
              ctx,
            )
          );

       if (mousePos.x > camera.width -. 50.0) {
         Camera.move(~point=Point.vector2(2.0, 0.0), camera);
       };

       if (mousePos.x < 50.0) {
         Camera.move(~point=Point.vector2(-2.0, 0.0), camera);
       };
     });
};

main();