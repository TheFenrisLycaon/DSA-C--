import os

try:
    import speech_recognition as sr
except Exception as e:
    print(e)
    os.system("python3 -m pip install SpeechRecognition")

rec = sr.Recognizer()

with sr.AudioFile("sampleaudio.wav") as source:
    data = rec.record(source)
    text = rec.recognize_google(data)
    with open("text.txt", "w") as f:
        f.write(text)


# print("Done")
