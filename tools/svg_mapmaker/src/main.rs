extern crate xml;

use std::fs::File;
use std::io::BufReader;

use xml::reader::{EventReader, XmlEvent};

struct Island {
    x: i32,
    y: i32,
    width: i32,
    height: i32
}

fn main() {
    let file = File::open("World2.svg").unwrap();
    let file = BufReader::new(file);

    let parser = EventReader::new(file);

    let islands = std::vec::Vec::<Island>::new();

    for e in parser {
        match e {
            Ok(XmlEvent::StartElement { name, attributes, namespace }) => {
                println!("START {}", name.local_name);

                if(name.local_name == "rect")
                {
                    attributes.iter().for_each(|x| println!("{}", x.name));
                }
            }
            Ok(XmlEvent::EndElement { name }) => {
                println!("END {}", name.local_name);
            }
            Err(e) => {
                println!("Error: {}", e);
                break;
            }
            _ => {}
        }
    }
}
