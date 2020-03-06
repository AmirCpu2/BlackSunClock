text = ''
f = open("htmlin.txt", "r")

for data in f:
    
    if '\"' in data:
        data = data.replace('\"','\\\"')
        # data = data.replace('<','\"<')
        # data = data.replace('>','\">')
        # data = data.replace('\"<','client.print(\"<')
        # data = data.replace('>\"','>\")')

    text += data.strip()

f.close()
# text=text.replace ('client.print(<'+data+'\"<')
# text=text.replace ('>'+data+'>\")')
# text=text.replace('\n\";','\"\n')
# text=text.replace('\";','\"')
text = text.replace('<','\nclient.println(\"<')
text = text.replace('function','\\nfunction')
text = text.replace(';',';\\n')
text = text.replace('>','>\");')
f = open("htmlout.txt", "w")
f.write(text)
f.close()
print(text)
