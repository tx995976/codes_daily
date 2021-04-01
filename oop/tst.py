import os;
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
driver = webdriver.Chrome("C:\Program Files\Google\Chrome\Application\chromedriver.exe") 
driver.get("http://59.69.101.2/index.php?mod=homeworkc&act=show&id=19")
cr_ele = driver.find_element_by_id("tbCode")
f = open("./oop/3.cpp","r")
str = f.read()
cr_ele.send_keys(str)
