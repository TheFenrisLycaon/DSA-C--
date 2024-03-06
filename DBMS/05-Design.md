# Design

## Conceptual Model

- The first step in design is to produce conceptual data model to define the structure of the database.
- The most widely used method to do this is the Entity-Relation model.
- Another mainstream approach is the Unified Modelling Language.

## Logical Model

- The next stage is to translate the model to a schema.
- It implements the relevant data structures inside the database.
- This process is called the logical dabase design and the resultant mdoel is called logical data model.

**NOTE** : The conceptual model is independent of the technologies to be used to create the database while, the logical model will be expressed in terms of the tech stack that is supported by the DBMS language.

## Relational Model

- The most widely used database model is the relational model as repesented by the SQL language.
- The process of creating logical database design using this mdoel is called normalization
- It ensures that each fundamental 'fact' is represented only once to maintain data consistency.

## Physical Model

- The final stage of design is physical stage where we create the physical data model.
- Here, we choose the tech stack that affects the performance, security, scalability and recovery of the database.
- The main goal is to maintain data independence to ensure that the decisions made for performance should be hidden from the end-users.

- Data independence is of two types :
  - Physical Data Independence
  - Logical Data Independence

- Another thing that the physical model takes care of is data security by defining both the access control and seurity methods and levels for the data.
