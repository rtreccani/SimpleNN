import sys, os

labelsfile = open("labels.ff", "rb")
imagesfile = open("images.ff", "rb")

stillReading = True
i = 0

labelsfile.read(8)
imagesfile.read(16)

while(stillReading):
    newSampleFile =open("data/training/" + str(i) + ".train", "wb")
    newSampleFile.write(labelsfile.read(1))
    newSampleFile.write(imagesfile.read(28*28))
    newSampleFile.close()
    i = i + 1
    if(i == 60000):
        stillReading = False
    
print("finished translating all samples")
