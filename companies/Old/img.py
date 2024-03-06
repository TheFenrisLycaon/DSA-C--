import os

try:
    from PIL import Image
    import pytesseract
except Exception as e:
    print(e)
    os.system("python3 -m pip install pillow pytesseract")
    from PIL import Image
    import pytesseract

im = Image.open("sample.jpg")
config = "-l eng --oem 1 --psm 3"
pytesseract.pytesseract.tesseract_cmd = "/bin/tesseract"
text = pytesseract.image_to_string(im, config=config)

with open("img.txt", "w") as f:
    f.write(text)
