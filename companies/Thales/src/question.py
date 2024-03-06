from datetime import datetime
import json

class Question:
    def __init__(self, problemStatement: str, correctAnswer: str, author: str, score: int) -> None:
        self.qstn = {
            "_Question__problemStatement" : problemStatement,
            "_Question__correctAnswer" : correctAnswer,
            "_Question__author" : author,
            "_Question_score" : score,
            "_Question_createdDate" : datetime.today().strftime('%Y-%m-%d')
        }
    
    def __repr__(self) -> str:
        return json.dumps(self.qstn)