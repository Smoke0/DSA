from bs4 import BeautifulSoup
import requests
import re
import urllib
import os
import argparse
import sys
import json

import urllib.request
request_url = urllib.request.urlopen('https://www.google.co.in/search?q=cat&source=lnms&tbm=isch')
print(request_url.read())