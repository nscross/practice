from PIL import Image, ImageFilter, ImageOps

if __name__ == '__main__':
    try:
        original = Image.open("Lenna.png")
        print "The size of the Image is: ",
        print(original.format, original.size, original.mode) 

        blurred = original.filter(ImageFilter.BLUR)
        contour = original.filter(ImageFilter.CONTOUR)
        detail = original.filter(ImageFilter.DETAIL)
        edge_enhance = original.filter(ImageFilter.EDGE_ENHANCE)
        edge_enhance_more = original.filter(ImageFilter.EDGE_ENHANCE_MORE)
        emboss = original.filter(ImageFilter.EMBOSS)
        find_edges = original.filter(ImageFilter.FIND_EDGES)
        smooth = original.filter(ImageFilter.SMOOTH)
        smooth_more = original.filter(ImageFilter.SMOOTH_MORE)
        sharpen = original.filter(ImageFilter.SHARPEN)

        original.show()
        blurred.show()
        smooth.show()

        blurred.save("blurred.png")
        contour.save("contour.png")
        detail.save("detail.png")
        edge_enhance.save("edge_enhance.png")
        edge_enhance_more.save("edge_enhance_more.png")        
        emboss.save("emboss.png")
        find_edges.save("find_edges.png")
        smooth.save("smooth.png")
        smooth_more.save("smooth_more.png")
        sharpen.save("sharpen.png")

    except:
        print "Unable to load image"