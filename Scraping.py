import requests 
from bs4 import BeautifulSoup

class MercadoLivre:
    def __init__(self):
        self.url = "https://celulares.mercadolivre.com.br/iphone"

    def get_page(self):
        request = requests.get(self.url)
        return BeautifulSoup(request.content, "html.parser")

    def get_phone_info(self):
        lists = self.html.find('ol',{'id': 'searchResults'}).findAll('li', {'class': 'results-item'})
        phones = []
        for _list in lists:
            phones.append({
                'Nome:': _list.find('span', {'class': 'main-title'}).text,
                'Preco:': _list.find('div', {'class': 'item__price'}).text
            })
            print(_list.find('span', {'class': 'main-title'}).text, end=', ')
            print('Preço:' + _list.find('div', {'class': 'item__price'}).text)
        return phones
        # import pdb; pdb.set_trace()

    def execute(self):
        self.html=self.get_page()
        self.get_phone_info()
        return self.get_phone_info()

        

if __name__ == '__main__':
    mercado_livre = MercadoLivre()
    phones = mercado_livre.execute()
    print('     ')
    print('----------------------------------------------- Json -----------------------------------------------')
    print('     ')
    for phone in phones:
        print(phone)
