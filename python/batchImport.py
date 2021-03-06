#!/usr/bin/env python
import json
import requests
from optparse import OptionParser

parser = OptionParser()
parser.add_option("-u", "--userId", dest="userId", type="string", action="store", help="UserId")
parser.add_option("-p", "--password", dest="password", type="string", action="store", help="Password")
parser.add_option("-c", "--community", dest="community", type="string", action="store", help="Community the userId has access to")
parser.add_option("-i", "--clientId", dest="clientId", type="string", action="store", help="OAuth2 client_id issued by Liquid Decisions to this application")
parser.add_option("-s", "--clientSecret", dest="clientSecret", type="string", action="store", help="OAuth2 client_secret issued by Liquid Decisions")
parser.add_option("-d", "--hostUrl", dest="hostUrl", type="string", action="store", help="LD Host URL")

parser.add_option("-E", "--notificationEmail", dest="notificationEmail", type="string", action="store", help="The email that is to be notified of job progress")
parser.add_option("-J", "--jobName", dest="jobName", type="string", action="store", help="The name to ")
parser.add_option("-C", "--contentType", dest="contentType", type="string", action="store", help="The type of file being uploaded")
parser.add_option("-I", "--itemType", dest="itemType", type="string", action="store", help="The item type thats being imported")
parser.add_option("-F", "--file", dest="file", type="string",action="store",help="The location of the file being uploaded")
parser.add_option("-T", "--template", dest="template", type="string",action="store",help="The location of the teamplate being uploaded")
parser.add_option("-M", "--merge", dest="merge", type="string",action="store",help="Merge files")
parser.add_option("-H", "--headers", dest="header", type="string",action="store",help="CSV file contains a header row")

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
print accessToken

files = {'file': (options.file, open(options.file, 'rb'), options.contentType, {'Expires': '0'}),
         'template': (options.template, open(options.template, 'rb'), 'application/json', {'Expires': '0'})}

parameters = {
		'notificationEmail': options.notificationEmail, 
		'jobName': options.jobName,
		'contentType':options.contentType,
		'itemType':options.itemType,
              'merge':options.merge,
              'headerRow':options.header}

resp = requests.post(options.hostUrl + '/ls/api/batch/import'.format(options.community), headers={'Authorization':'Bearer ' + accessToken}, files=files, data=parameters)
print resp.text

