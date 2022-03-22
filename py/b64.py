import base64

f=open('abc244.png','rb')
out = open('out.txt','wb')
code_png = base64.b64encode(f.read())
f.close()
out.write(code_png)

