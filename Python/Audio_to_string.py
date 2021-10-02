import wave, math, contextlib
import speech_recognition as sr
from moviepy.editor import AudioFileClip
transcribed_audio_file_name = "transcribed_speech.wav"
zoom_video_file_name = "nw.wav"
audioclip = AudioFileClip(zoom_video_file_name)
audioclip.write_audiofile(transcribed_audio_file_name)
with contextlib.closing(wave.open(transcribed_audio_file_name,'r')) as f:
    frames = f.getnframes()
    print(frames)
    rate = f.getframerate()
    print(rate)
    duration = frames / float(rate)
    print(duration)
total_duration = math.ceil(duration / 60)
print(total_duration)
r = sr.Recognizer()
for i in range(0, total_duration):
    with sr.AudioFile(transcribed_audio_file_name) as source:
        audio = r.record(source, offset=i*60, duration=60)
    f = open("transcription.txt", "a")
    f.write(r.recognize_google(audio))
    f.write(" ")
f.close()