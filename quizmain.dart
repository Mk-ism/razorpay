import 'package:flutter/material.dart';

// import './question.dart';
// import './answer.dart';
import './quiz.dart';
import './result.dart';

// void main() {
//   runApp(MyApp());
// }
//
void main() => runApp(MyApp());

class MyApp extends StatefulWidget {
  @override
  State<StatefulWidget> createState() {
    // TODO: implement createState
    return _MyAppState();
  }
}

class _MyAppState extends State<MyApp> {
  final _questions = const [
    {
      "questionText": "What's your favourite color?",
      "answers": [
        {"text": "Black", "score": 10},
        {"text": "red", "score": 5},
        {"text": "Green", "score": 3},
        {"text": "White", "score": 1},
      ]
    },
    {
      "questionText": "What's your favourite animal?",
      "answers": [
        {"text": "Cat", "score": 1},
        {"text": "Dog", "score": 5},
        {"text": "Rabbit", "score": 3},
        {"text": "Lion", "score": 10},
      ]
    },
    {
      "questionText": "What's your favourite destination?",
      "answers": [
        {"text": "Goa", "score": 1},
        {"text": "New York", "score": 5},
        {"text": "London", "score": 3},
        {"text": "Thailand", "score": 10},
      ]
    },
    {
      "questionText": "What's your favourite drink?",
      "answers": [
        {"text": "Maza", "score": 1},
        {"text": "Pepsi", "score": 5},
        {"text": "Juice", "score": 3},
        {"text": "Cola", "score": 10},
      ]
    },
    {
      "questionText": "What's your favourite Food?",
      "answers": [
        {"text": "Salad", "score": 1},
        {"text": "Burger", "score": 5},
        {"text": "Momo", "score": 3},
        {"text": "Pizza", "score": 10},
      ]
    },
  ];
  var _questionIndex = 0;
  var _totalScore = 0;

  void _resetQuiz() {
    setState(() {
      _questionIndex = 0;
      _totalScore = 0;
    });
  }

  void _answerQuestion(int score) {
    _totalScore += score;

    setState(() {
      _questionIndex = _questionIndex + 1;
    });
    print(_questionIndex);
    if (_questionIndex < _questions.length) {
      print("we have more questions");
    }
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: Scaffold(
        appBar: AppBar(
          title: Text("My App"),
        ),
        body: _questionIndex < _questions.length
            ? Quiz(
                answerQuestion: _answerQuestion,
                questionIndex: _questionIndex,
                questions: _questions,
              )
            : Result(_totalScore, _resetQuiz),
      ),
    );
  }
}
