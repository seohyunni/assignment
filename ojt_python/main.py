from urllib.error import HTTPError
import urllib.request
from bs4 import BeautifulSoup
import ssl

context = ssl._create_unverified_context() #https url error 방지
url = 'http://www.yes24.com/Product/Search?domain=ALL&query=python'

try:
    html = urllib.request.urlopen(url).read()
    soup = BeautifulSoup(html,'html.parser')

    book_list = soup.find_all(class_='gd_name')
    price_list = soup.find_all(class_='txt_num')

    book_title = []
    book_price = []
        
    for result_title in book_list :
        title = result_title.get_text()
        book_title.append(title)
        
    for result_price in price_list :
        price = result_price.get_text()
        book_price.append(price)
        
    for i in range(len(book_title)) :
        print(book_title[i], ' - ', book_price[i])

except HTTPError as e:
    err = e.read()
    code = e.getcode()
    print(code, "잘못된 주소입니다.")

    