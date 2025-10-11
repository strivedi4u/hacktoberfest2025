import requests
from bs4 import BeautifulSoup

def fetch_cricbuzz_data():
    """
    Fetches the latest live cricket match details from Cricbuzz.com.

    This function sends an HTTP request to Cricbuzz, retrieves the HTML content of the live matches page,
    parses the content using BeautifulSoup, and extracts details of live cricket matches such as teams, scores,
    and match status.

    Returns:
        list[dict]: A list of dictionaries where each dictionary contains details of a live cricket match.
                    Each dictionary has keys like 'match_title', 'team1', 'team2', 'score1', 'score2', and 'status'.
    """
    url = "https://www.cricbuzz.com/cricket-match/live-scores"  # URL for live scores
    headers = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3"
    }
    
    # Fetch the webpage content
    response = requests.get(url, headers=headers)
    
    if response.status_code != 200:
        print("Failed to fetch the page. Status code:", response.status_code)
        return []
    
    # Parse the page using BeautifulSoup
    soup = BeautifulSoup(response.content, "html.parser")
    
    # Find the section that contains live matches (use inspection tools to find appropriate HTML structure)
    matches = soup.find_all('div', class_='cb-col cb-col-100 cb-ltst-wgt-hdr')  # Live match containers

    match_data = []

    # Loop through each match and extract relevant information
    for match in matches:
        match_title = match.find('h2').get_text()  # Match title (e.g., Team1 vs Team2)
        
        # Extract team and score information
        teams = match.find_all('div', class_='cb-ovr-flo')  # Container with team names and scores
        if len(teams) >= 2:
            team1 = teams[0].get_text().split(" ", 1)[0]  # First team name
            team2 = teams[1].get_text().split(" ", 1)[0]  # Second team name
            score1 = teams[0].get_text().split(" ", 1)[1] if len(teams[0].get_text().split(" ", 1)) > 1 else "N/A"
            score2 = teams[1].get_text().split(" ", 1)[1] if len(teams[1].get_text().split(" ", 1)) > 1 else "N/A"
        else:
            team1, team2, score1, score2 = "N/A", "N/A", "N/A", "N/A"
        
        # Extract match status (e.g., In progress, Completed, etc.)
        status = match.find('div', class_='cb-text-live').get_text() if match.find('div', class_='cb-text-live') else "N/A"
        
        # Append the extracted match data into a structured format
        match_data.append({
            "match_title": match_title,
            "team1": team1,
            "score1": score1,
            "team2": team2,
            "score2": score2,
            "status": status
        })

    return match_data

def display_matches(matches):
    """
    Display match data in a readable format.

    Args:
        matches (list[dict]): List of dictionaries containing match details.
    """
    if not matches:
        print("No live matches available at the moment.")
        return
    
    print(f"{'Match':<30} {'Team 1':<15} {'Score 1':<10} {'Team 2':<15} {'Score 2':<10} {'Status'}")
    print("=" * 85)
    
    for match in matches:
        print(f"{match['match_title']:<30} {match['team1']:<15} {match['score1']:<10} {match['team2']:<15} {match['score2']:<10} {match['status']}")

if __name__ == "__main__":
    # Fetch latest cricket match data from Cricbuzz
    live_matches = fetch_cricbuzz_data()

    # Display the fetched match data
    display_matches(live_matches)
