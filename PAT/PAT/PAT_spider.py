#!/usr/bin/python

import urllib   
import urllib2  
import sys
import re
from bs4 import BeautifulSoup

LevelBIndexURL = 'https://www.patest.cn/contests/pat-b-practise' 
LevelBURL = 'https://www.patest.cn'
type = sys.getfilesystemencoding()

header = {'User-Agent':'Mozilla/5.0 (Windows; U; Windows NT 6.1; en-US; rv:1.9.1.6) Gecko/20091201 Firefox/3.5.6'}  

def getItemURL():
    list = []
    req = urllib2.Request(LevelBIndexURL, headers = header)
    con = urllib2.urlopen(req)
    doc = con.read()
    con.close()
    doc =  doc.decode("UTF-8").encode(type)  
    file = open('index.html' , 'a')
    file.write(doc)
    file.close()
    # print doc
    soup = BeautifulSoup(doc, 'html.parser')
    for link in soup.find_all(href=re.compile("pat-b-practise/10[0-9][0-9]")):
        list.append(link.get("href"))

    return list

def getItem():
    text = ""
    list = getItemURL()
    file = open('test.txt' , 'a')
    tempURL = LevelBURL + list[0];
    # print tempURL   
    req = urllib2.Request(tempURL, headers = header)
    con = urllib2.urlopen(req)
    doc = con.read()
    con.close()
    doc =  doc.decode("UTF-8").encode(type)
    soup = BeautifulSoup(doc, 'html.parser')
    item = soup.find_all('div', attrs={"id":"problemContent"})
    text = soup.h1.string.encode('UTF-8') + '\n'
    for i in item:
         url_list = i.find_all('p')
         for j in url_list:
             print j.string
            #  print type(j.string)
            #  if j.strip() != '':
                # print j.string
    # text = text + item[0].string.encode('UTF-8')
    file.write(text)
    file.close()

getItem()
