import '../models/transaction.dart';
import 'package:flutter/material.dart';

class Report extends StatelessWidget {
  final List<Transaction> transactions;

  Report(this.transactions);

  @override
  Widget build(BuildContext context) {
    // double total = 0.0;

    // final count = (transactions.length);

    // for (int i = 0; i < count; i++) {
    //   total += transactions[i].amount;
    // }
    //
    transactions.map((tx) {}).toList();

    double total = 0.0;

    final count = (transactions.length);

    for (int i = 0; i < count; i++) {
      total += transactions[i].amount;
    }

    return Container(
      // children: transactions.map((tx) {
      //   return Text(total.toString());
      // }).toList(),
      child: Text(total.toString()),
    );
  }
}
