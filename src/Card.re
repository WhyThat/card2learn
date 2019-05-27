/* State declaration */
type state = {
  showAnswer: bool,
  lastDifficulty: CardType.difficulty,
};

/* Action declaration */
type action =
  | Hide
  | Show;

let initialState = {showAnswer: false, lastDifficulty: None};

let reducer = (state, action) =>
  switch (action) {
  | Hide => {...state, showAnswer: false}
  | Show => {...state, showAnswer: true}
  };

[@react.component]
let make = (~question, ~answer, ~validateAnswer) => {
  let (state, dispatch) = React.useReducer(reducer, initialState);

  let handleValidateAnswer = difficulty => {
    dispatch(Hide);
    validateAnswer(difficulty);
  };

  <div>
    {ReasonReact.string(question)}
    <button onClick={_event => dispatch(Show)}>
      {ReasonReact.string("Show Answer")}
    </button>
    <Answer
      text=answer
      isShown={state.showAnswer}
      validateAnswer=handleValidateAnswer
    />
  </div>;
};