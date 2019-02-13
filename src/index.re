open Webapi.Dom;
open Webapi.Canvas.CanvasElement;
open App;


let main = () => {
  let canvas =
    Belt.Option.(document |> Document.getElementById("app") |> getExn);

  let ctx = getContext2d(canvas);

  let pl1 = Player.make();

  switch (pl1.graphic.show) {
  | Some(show) => show(ctx, pl1)
  | None => ()
  };
};

main();
