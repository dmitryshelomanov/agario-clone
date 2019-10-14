open Webapi.Canvas.Canvas2d;
open Point;

[@bs.deriving jsConverter]
type align = [
  | [@bs.as "end"] `End
  | [@bs.as "start"] `Start
  | [@bs.as "center"] `Center
];

type textStyle = {
  font: string,
  fill: string,
  align,
};

let circle = (~point, ~r, ~color="black", ctx) => {
  let {x, y} = point;

  save(ctx);
  translate(~x, ~y, ctx);
  beginPath(ctx);
  arc(
    ~x=0.0,
    ~y=0.0,
    ~r,
    ~startAngle=0.0,
    ~endAngle=Js.Math._PI *. 2.0,
    ~anticw=false,
    ctx,
  );
  setFillStyle(ctx, String, color);
  fill(ctx);
  restore(ctx);
};

let rect = (~point, ~color="black", ~size: Size.t, ~angle=0.0, ctx) => {
  let {x, y} = point;
  let (w, h) = size;
  let pivot = 0.5;

  ctx |> save;
  ctx |> translate(~x, ~y);
  color |> setFillStyle(ctx, String);
  ctx |> rotate(angle *. Js.Math._PI /. 180.0);
  ctx |> translate(~x=w *. pivot *. (-1.0), ~y=h *. pivot *. (-1.0));
  ctx |> fillRect(~x=0.0, ~y=0.0, ~w, ~h);
  ctx |> restore;
};

let text = (~point, ~text, ~style: textStyle, ctx) => {
  let {x, y} = point;

  ctx |> save;
  ctx |> translate(~x, ~y);
  style.font |> font(ctx);
  alignToJs(style.align) |> textAlign(ctx);
  style.fill |> setFillStyle(ctx, String);
  ctx |> fillText(text, ~x=0.0, ~y=0.0);
  ctx |> restore;
};

let renderTexsts =
    (~point, ~style: textStyle, ~texts: array(string), ~lineHeight=15.0, ctx) => {
  let lineHeight = Point.vector2(0.0, lineHeight);

  texts
  |> Js_array.forEachi((str, index) => {
       let index' = float_of_int(index);
       let point' = Point.(point + lineHeight * index');

       ctx |> text(~point=point', ~style, ~text=str);
     });
};