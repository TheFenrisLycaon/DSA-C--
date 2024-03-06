import requests

fromdata = r"regno=15178564&sch=30930&dob=03%2F11%2F2005&B2=Submit"

headers = {"regno": "15178564", "sch": "30930", "dob": "03%2F11%2F2005", "B2": "Submit"}

rollNo = 15178564
schoolCode = 30930
dob = "03/11/2005"

k = requests.get(
    url="https://cbseresults.nic.in/class10/class10th21.asp", headers=headers
)

print(k.text)
