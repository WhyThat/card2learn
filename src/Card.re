/* State declaration */
type state = {
  showAnswer: bool,
  lastDifficulty: CardType.difficulty,
};

/* Action declaration */
type action = Show | SetDifficulty(CardType.difficulty);

let initialState = {
  showAnswer: false,
  lastDifficulty: None,
};

let reducer = (state, action) =>
  switch (action) {
  | Show => {...state, showAnswer: true}
  | SetDifficulty(level) => { ...state, lastDifficulty: level }
  };


[@react.component]
let make = (~question, ~answer, ~setDifficulty) => {
  let (state, dispatch) = React.useReducer(reducer, initialState);
  Js.log("re-render");

  <div>
    {ReasonReact.string(question)}
    <button onClick={_event => dispatch(Show)}>
      {ReasonReact.string("Show Answer")}
    </button>
    <Answer text=answer isShown=state.showAnswer dispatch={setDifficulty}/>
  </div>
  };
