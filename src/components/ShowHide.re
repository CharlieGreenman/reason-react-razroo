/* State declaration */
type state = {
  show: bool,
};

/* Action declaration */
type action =
  | Toggle;

let component = ReasonReact.reducerComponent("ShowHide");

let make = (~greeting, _children) => {
  /* spread the other default fields of component here and override a few */
  ...component,

  initialState: () => {show: true},

  /* State transitions */
  reducer: (action, state) =>
    switch (action) {
    | Toggle => ReasonReact.Update({...state, show: ! state.show})
    },

  render: self => {
    <div>
      <button onClick=(_event => self.send(Toggle))>
        (ReasonReact.stringToElement("Toggle greeting"))
      </button>
      (
        self.state.show ?
          ReasonReact.stringToElement(greeting) : ReasonReact.nullElement
      )
    </div>;
  },
};
