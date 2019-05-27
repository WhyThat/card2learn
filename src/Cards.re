type state = {currentIndex: int};
type action =
  | SetDifficulty(CardType.difficulty);

let reducer = (state, action) =>
  switch (action) {
  | SetDifficulty(_) => {currentIndex: state.currentIndex + 1}
  };

let initialState = {currentIndex: 0};

[@react.component]
let make = (~cards: list(CardType.card)) => {
  let (state, dispatch) = React.useReducer(reducer, initialState);
  let toCard = cardOpt =>
    switch (cardOpt) {
    | Some((card: CardType.card)) =>
      <Card
        question={card.question}
        answer={card.answer}
        validateAnswer=(difficulty => dispatch(SetDifficulty(difficulty)))
      />
    | None => React.string("No more cards")
    };

  let cardsElements =
    (
      state.currentIndex < List.length(cards) ?
        Some(List.nth(cards, state.currentIndex)) : None
    )
    |> toCard;
  <div> cardsElements </div>;
};