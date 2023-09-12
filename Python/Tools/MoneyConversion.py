import requests
from bs4 import BeautifulSoup
from vietnam_number import n2w

url = 'https://wise.com/vi/currency-converter/usd-to-vnd-rate'
print(f"Connecting to {url}...")
response = requests.get(url)

if response.status_code != 200:
    print(f"error: {response.status_code}")
    input()
    exit()
else:
    soup = BeautifulSoup(response.text, 'html.parser')
    rate_element = soup.find('span', class_="text-success")
    rate_value = rate_element.get_text()
    time = soup.find('small', class_="m-r-1").get_text()

    print(f"1 USD = {rate_value} VND. {time}")

input_value = input("Enter USD: ")
usd = float(input_value)
vnd = usd * float(rate_value.replace(',', ''))
print(f"{usd} USD = {vnd} VND. {n2w(str(int(vnd)))} đồng")

#wait
input()