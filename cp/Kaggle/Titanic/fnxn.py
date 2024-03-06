
def classifyWithLogisticRegression(trainingData, results, testData):
    clf_logreg = LogisticRegression()
    clf_logreg.fit(trainingData, results)
    return clf_logreg.predict(testData)


def classifyWithDecisionTree(trainingData, results, testData):
    clf_tree = tree.DecisionTreeClassifier()
    clf_tree.fit(trainingData, results)
    return clf_tree.predict(testData)


def classifyWithSVM(trainingData, results, testData):
    clf_svm = SVC()
    clf_svm.fit(trainingData, results)
    return clf_svm.predict(testData)


def classifyWithPerceptron(trainingData, results, testData):
    clf_perceptron = Perceptron()
    clf_perceptron.fit(trainingData, results)
    return clf_perceptron.predict(testData)


def classifyWithKNeighbors(trainingData, results, testData):
    clf_KNN = KNeighborsClassifier()
    clf_KNN.fit(trainingData, results)
    return clf_KNN.predict(testData)


def classifyWithGaussianNaiveBayes(trainingData, results, testData):
    clf_GaussianNB = GaussianNB()
    clf_GaussianNB.fit(trainingData, results)
    return clf_GaussianNB.predict(testData)


def classifyWithStochasticGradientDescent(trainingData, results, testData):
    sgd = SGDClassifier()
    sgd.fit(trainingData, results)
    return sgd.predict(testData)


def classifyWithLinearSVC(trainingData, results, testData):
    linear_svc = LinearSVC()
    linear_svc.fit(trainingData, results)
    return linear_svc.predict(testData)


def classifyWithRandomForest(trainingData, results, testData):
    random_forest = RandomForestClassifier(n_estimators=100)
    random_forest.fit(trainingData, results)
    return random_forest.predict(testData)

