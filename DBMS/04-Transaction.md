# Transactions

Any logical calculation done in a consistent mode in a database is called a transaction. Transactions show that a unit of work has been performed on a database and signifies a changes in a database. A transaction should be independent of the other transactions. It has two main purposes :

- To provide reliable unit of work that can be recovered from failures. It keeps a database consistent.
- To provide isolation between programs accessing the database concurrently.

A transaction must follow ACID, i.e.:

- Atomic : Complete in it's own and have no effect.
- Consistent : Must conform to the exixting database.
- Isolated : Must not affect othe transactions.
- Durable : Must get written into persistent storage.
