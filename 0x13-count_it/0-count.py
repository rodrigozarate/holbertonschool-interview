#!/usr/bin/python3
""" Doc to counter of hot reddit topics """
from re import findall, IGNORECASE
from requests import get


def count_words(subreddit, word_list, word_totals={}, after=''):
    """ Search over redit articles
        Arguments:
            subreddit (string): topic
            word_list (list): words to search for
            word_totals (dict): count register
            after (string): page

        Return: dict count register
    """
    limit = 100

    url = 'https://www.reddit.com/r/{}/hot.json?raw_json=1&after={}&limit={}'
    response = get(url.format(subreddit, after, limit),
                   headers={'User-Agent': 'holbybot'})

    if response.status_code != 200 or len(word_list) == 0:
        return

    regex = '^{}$|^{} +| +{} +| +{}$'
    word_count = dict.fromkeys([word.lower() for word in word_list], 0)
    current_page_list = response.json().get('data').get('children', [])

    for post in current_page_list:
        title = post.get('data').get('title', '')
        for word in word_list:
            count = len(findall(regex.format(word, word, word, word),
                                title, IGNORECASE))
            word_count[word.lower()] += count

    for key, value in word_count.items():
        if key in word_totals:
            word_totals[key] += value
        else:
            word_totals[key] = value

    if len(current_page_list) < limit:
        for item in sorted(word_totals.items(),
                           key=lambda item: (-item[1], item[0])):
            if item[1] > 0:
                print('{}: {}'.format(item[0], item[1]))
        return

    after = current_page_list[-1].get('data').get('name', '')
    return count_words(subreddit, word_list, word_totals, after)
