extern crate ferris_says;

use ferris_says::say;
use std::io::{ stdout, BufWriter };

fn main() {
    let mut writer = BufWriter::new(stdout());
    let s = b"Hello, rust!";

    say(s, s.len(), &mut writer).unwrap();
}
