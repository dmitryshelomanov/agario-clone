open Webapi.Canvas;

type t('a) = {
  show: option((Canvas2d.t, 'a) => unit),
  update: option((Canvas2d.t, 'a) => unit),
};

let makeGraphic = (~show=None, ~update=None, ()) => {
  show,
  update,
};
