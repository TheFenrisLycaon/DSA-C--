def domain_name(url):
    k = url.replace("//", "#").replace("/", "#").replace(".", "#").split("#")
    while "http" in k[0]  or "www" in k[0]:
        k = k[1:]
    return k[0]


print(domain_name("http://google.com"))
print(domain_name("http://google.co.jp"))
print(domain_name("www.xakep.ru"))
print(domain_name("https://youtube.com"))