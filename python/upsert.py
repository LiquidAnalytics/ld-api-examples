'''
Created on Jan 31, 2014

@author: olegdulin-la
'''
import requests
import json
import time

import requests
import json
from optparse import OptionParser

parser = OptionParser()
parser.add_option("-u", "--userId", dest="userId", type="string",
                  action="store", help="UserId")
parser.add_option("-p", "--password", dest="password", type="string",
                  action="store", help="Password")
parser.add_option("-c", "--community", dest="community", type="string", action="store", help="Community the userId has access to")
parser.add_option("-i", "--clientId", dest="clientId", type="string", action="store", help="OAuth2 client_id issued by Liquid Decisions to this application")
parser.add_option("-s", "--clientSecret", dest="clientSecret", type="string", action="store", help="OAuth2 client_secret issued by Liquid Decisions")
parser.add_option("-d", "--hostUrl", dest="hostUrl", type="string", action="store", help="LD Host URL")
parser.add_option("-f", "--file", dest="itemsFile", type="string", action="store", help="Items to upsert")
(options, args) = parser.parse_args()

resp = requests.post(options.hostUrl + '/ls/api/oauth2/token', data={
       "grant_type":"password",
       "client_id":options.clientId,
       "client_secret":options.clientSecret,
       "username": options.userId,
       "password":options.password,
       "scope":"community=" + options.community})

accessInfo = json.loads(resp.text)
accessToken = accessInfo['access_token']

f = open(options.itemsFile, 'r')
data = json.load(f)


headers = {'content-type':'application/json', 'Authorization':'Bearer ' + accessToken}
resp = requests.post(options.hostUrl + '/ls/api/items/upsert', data=json.dumps(data), headers=headers)

print resp.text