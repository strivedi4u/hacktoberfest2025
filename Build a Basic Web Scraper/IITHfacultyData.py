import requests
from bs4 import BeautifulSoup
import json

url = "https://www.iith.ac.in/people/faculty/"
request = requests.get(url)

soup = BeautifulSoup(request.content, "html.parser")
faculty_cards = soup.find_all("div", class_="facultycard")

info_list = []

for i, card in enumerate(faculty_cards):
    if i >= 15:
        break

    nextlink = card.find("a")
    subpage = "https://www.iith.ac.in/" + nextlink['href']
    
    request1 = requests.get(subpage)
    subpagesoup = BeautifulSoup(request1.content, "html.parser")

    site_content_div = subpagesoup.find("div", class_="site-content")
    test_text = site_content_div.find("div", class_="col-sm-9 article-post").get_text().split('\n')
    scraped_text = list(filter(None, list(map(str.strip, test_text))))

    info = {}
    info['name'] = scraped_text[0]
    current_key = None

    for line in scraped_text:
        if line.startswith('Room:'):
            continue

        if ':' in line:
            current_key, *current_value = line.split(':')
            current_key = current_key.strip()
            current_value = ":".join(current_value).strip()

            if current_key == 'Department(s)' or current_key == 'Research Interests' or current_key == 'Office Address':
                info[current_key.lower()] = []
            else:
                info[current_key.lower()] = current_value
        elif current_key in ['Department(s)', 'Research Interests', 'Office Address']:
            if line.strip():
                info[current_key.lower()].append(line.strip())

    info_list.append(info)

# Save the info_list to a JSON file
with open('faculty_info.json', 'w') as json_file:
    json.dump(info_list, json_file, indent=4)

print("Data has been saved to faculty_info.json")
