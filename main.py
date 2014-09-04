
import urllib2
import os
import re
from HTMLParser import HTMLParser

# create a subclass and override the handler methods
class MyHTMLParser(HTMLParser):
    
    print_status=False

    def gen_items(self, html, output_file):
        self.file = open(output_file, 'w')
        self.feed(html)
        

    def handle_starttag(self, tag, attrs):
        self.print_status = self.print_status or tag=='script'

    def handle_endtag(self, tag):
        if tag=='script':
            self.print_status=False

    def handle_data(self, data):
        if self.print_status:
            items = parse(data,'{','}')

            if(len(items) > 10):
                self.file.write('\n<Items>\n')
                for it in items:
                    item = Item(it)
                    if(item.name != ''):
                        print "Found " + item.name + " !"
                        self.file.write(item.to_xml(1))
                self.file.write('<\Items>\n')

class Item:
    
    int_param = ['id','icon','slotId','lvl','ap','capacity','circleGems','squareGems','triangleGems','runeType','runeCount']
    int_regex = '"{}":([0-9]+?),'
    int_default = -1
    
    float_param = ['patch']
    float_regex = '"{}":([0-9]+\.[0-9]+),'
    float_default = -1.0

    string_param = ['name','description','conditions','requirements','slot','quality','rarity','children']
    string_regex = '"{}":"(.*?)",'
    string_default = ""

    stats = {
            '20':'HP',
            '26':'percent_heals',
            '31':'AP',
            '41':'MP',

            '46':'percent_resis_MP_loss',

            '71':'percent_resis_behind',
            '72':'percent_resis_heal',

            '80':'percent_resis_all',
            '82':'percent_resis_fire',
            '83':'percent_resis_water',
            '84':'percent_resis_earth',
            '85':'percent_resis_air',

            '93':'negative_percent_resis_fire',
            '94':'negative_percent_resis_water',

            '120':'percent_all_dmg',
            '122':'percent_fire_dmg',
            '123':'percent_earth_dmg',
            '124':'percent_water_dmg',
            '125':'percent_air_dmg',

            '132':'negative_percent_fire_dmg',
            '133':'negative_percent_earth_dmg',
            '135':'negative_percent_air_dmg',

            '149':'percent_critical_hit_dmg',
            '150':'percent_critical_hit',

            '152':'agility',
            '154':'stength',
            '156':'intelligence',
            '158':'chance',

            '160':'range',
            '162':'prospecting',
            '166':'wisdom',

            '171':'initiative',
            '172':'negative_initiative',
            '173':'lock',
            '175':'dodge',
            '176':'negative_dodge',

            '180':'percent_backstab_dmg',
            '184':'control',

            '234':'Kit Skill',
            '235':'percent_remove_AP',
            
            '838':'CMC_dmg',
            '875':'block',

            '988':'percent_resis'
            }
    

    def __init__(self, str):

        for i in Item.int_param:
            regex=Item.int_regex.format(i)
            match = re.search(regex, str)
            if(match):
                setattr(self, i, int(match.group(1)))
            else:
                setattr(self, i, Item.int_default)
        
        for i in Item.float_param:
            regex=Item.float_regex.format(i)
            match = re.search(regex, str)
            if(match):
                setattr(self, i, float(match.group(1)))
            else:
                setattr(self, i, Item.float_default)
        
        for i in Item.string_param:
            regex=Item.string_regex.format(i)
            match = re.search(regex, str)
            if(match):
                setattr(self, i, match.group(1))
            else:
                setattr(self, i, Item.string_default)

        #item attribs
        self.stats=[]
        match = re.search('"stats":{"ITEM_EQUIP":{(.*?)}', str)
        if(match):
            stats = match.group(1)
            match = re.search('"NORMAL":\[(.*)\]', stats)
            if(match):
                normal = match.group(1)
                caracteristics = re.findall('\[(.*?),(.*?),(.*?),(.*?)\]', normal)
                for c in caracteristics:
                    self.stats.append((c[0],c[2]))

        
        
    def __str__(self):
        return 'Item with id {}\n\t{}\tlvl {}\n\t{}'.format(self.id, self.name, self.lvl, self.description)

    def to_xml(self, indent):
        xml=''
        
        if (self.id != Item.int_default):
            
            xml += indent*'\t'+'<Item>'+'\n'
            indent += 1
    
            xml += (indent*'\t'+'<ID>'+str(self.id)+'<\ID>'+'\n')
            xml += (indent*'\t'+'<Name>'+str(self.name)+'<\Name>'+'\n' if self.name != Item.string_default else '')
            xml += (indent*'\t'+'<Level>'+str(self.lvl)+'<\Level>'+'\n' if self.lvl != Item.int_default else '')
            xml += (indent*'\t'+'<Description>'+str(self.description)+'<\Description>'+'\n' if self.description != Item.string_default else '')
            xml += (indent*'\t'+'<Slot>'+str(self.slot)+'<\Slot>'+'\n' if self.slot != Item.string_default else '')
            xml += (indent*'\t'+'<SlotID>'+str(self.slotId)+'<\SlotID>'+'\n' if self.slotId != Item.int_default else '')
            xml += (indent*'\t'+'<Rarity>'+str(self.rarity)+'<\Rarity>'+'\n' if self.rarity != Item.string_default else '')
            xml += (indent*'\t'+'<Quality>'+str(self.quality)+'<\Quality>'+'\n' if self.quality != Item.string_default else '')
            xml += (indent*'\t'+'<Conditions>'+str(self.conditions)+'<\Conditions>'+'\n' if self.conditions != Item.string_default else '')
            xml += (indent*'\t'+'<Requirements>'+str(self.requirements)+'<\Requirements>'+'\n' if self.requirements != Item.string_default else '')
            xml += (indent*'\t'+'<Children>'+str(self.children)+'<\Children>'+'\n' if self.children != Item.string_default else '')
            xml += (indent*'\t'+'<Icon>'+str(self.icon)+'<\Icon>'+'\n' if self.icon != Item.int_default else '')
            xml += (indent*'\t'+'<AP>'+str(self.ap)+'<\AP>'+'\n' if self.ap != Item.int_default else '')
            xml += (indent*'\t'+'<Capacity>'+str(self.capacity)+'<\Capacity>'+'\n' if self.capacity != Item.int_default else '')
            xml += (indent*'\t'+'<Patch>'+str(self.patch)+'<\Patch>'+'\n' if self.patch != Item.float_default else '')
            xml += (indent*'\t'+'<RuneCount>'+str(self.runeCount)+'<\RuneCount>'+'\n' if self.runeCount != Item.int_default else '')

                #xml += (indent*'\t'+'<Circle>'+str(self.circleGems)+'<\Circle>'+'\n' if self.circleGems != Item.int_default else '')
                #xml += (indent*'\t'+'<Square>'+str(self.squareGems)+'<\Square>'+'\n' if self.squareGems != Item.int_default else '')
                #xml += (indent*'\t'+'<Triangle>'+str(self.triangleGems)+'<\Triangle>'+'\n' if self.triangleGems != Item.int_default else '')
                #xml += (indent*'\t'+'<RuneType>'+str(self.runeType)+'<\RuneType>'+'\n' if self.triangleGems != Item.int_default else '')

            if(len(self.stats) > 0):
                xml+= indent*'\t'+'<Stats>'+'\n'
                indent += 1
                for i in self.stats:
                    xml += indent*'\t'
                    xml +='<Stat>'
                    xml +='<ID>'+ i[0]+'<\ID>'
                    xml += '<Value>'+i[1]+'<\\Value>'
                    xml +='<\Stat>'+'\n'
                
                indent -= 1
                xml += indent*'\t'+'<\Stats>'+'\n'

            indent -= 1
            xml += indent*'\t' + '<\Item>' + '\n\n'

        return xml



def parse(string, open_caracter, close_caracter):
    items = []
    counter=0
    str=''
    for c in string:
    
        if counter==0 and (c==',' or c=='\t'):
            continue

        if c==open_caracter:
            counter+=1
        
        if c==close_caracter:
            counter-=1
            if counter==0:
                items.append(str) 
                str=''
                continue
        
        str = str + c

    return items

    



stats = {
            '101':'axes',
            '103':'rings',
            '108':'wands',
            '110':'one_handed_swords',
            '111':'showels',
            '112':'daggers',
            '113':'one_handed_staffs',
            '114':'hammers',
            '115':'hands',
            '117':'bows',
            '119':'boots',
            '120':'amulets',
            '132':'cloaks',
            '133':'belts',
            '134':'helmets',
            '136':'breastplates',
            '138':'epaulettes',
            '189':'shields',
            '223':'two_handed_swords',
            '253':'two_handed_staffs',
            '254':'cards'
        }


url='http://wakfu-elements.com/items/type/'
parser = MyHTMLParser()

for key in stats.keys():
    response = urllib2.urlopen(url+key)
    html = response.read()
    parser.gen_items(html,stats[key]+'.xml')


