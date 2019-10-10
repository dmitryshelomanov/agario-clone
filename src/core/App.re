open Webapi.Canvas;

let looper = (callback: unit => unit, ctx: Canvas2d.t) => {
  let rec loop = _t => {
    Canvas.clear(
      ~w=Canvas.context2dToJsObj(ctx)##canvas##width,
      ~h=Canvas.context2dToJsObj(ctx)##canvas##height,
      ctx,
    );

    callback();
    Webapi.requestAnimationFrame(loop);
  };

  Webapi.requestAnimationFrame(loop);
};