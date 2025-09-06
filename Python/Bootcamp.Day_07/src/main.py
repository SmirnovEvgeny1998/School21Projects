import load_questions
import interrogation

if __name__ == "__main__":
    load_questions.CreateQuestionDB()
    interrogation.ask_questions()
