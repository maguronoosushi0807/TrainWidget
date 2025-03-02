const white  = "#F2F0F1";
const orange = "#FF831F";

let loc_now  = "Iwade";
let loc_dest = "Miyamae";

let ItW = new Array();
let WtI = new Array();
let MtW = new Array();
let WtM = new Array();


// 読み出し
async function load(){
  const ItW_file = await fetch("asset/ItW.csv");
  const WtI_file = await fetch('asset/WtI.csv');
  const MtW_file = await fetch('asset/MtW.csv');
  const WtM_file = await fetch('asset/WtM.csv');
  
  const ItW_text = await ItW_file.text();
  const WtI_text = await WtI_file.text();
  const MtW_text = await MtW_file.text();
  const WtM_text = await WtM_file.text();


  const ItW_split = ItW_text.split(/,|\n/);
  ItW_split.forEach(function(value, index){
    let is_rapid = false;

    if(value.startsWith('_')){
      is_rapid = true;
      value = value.slice(1);
    }

    let hour = Number(value.substring(0,2));
    let min  = Number(value.substring(2,4));

    ItW.push(hour*60+min, is_rapid)
  })


  const WtI_split = WtI_text.split(/,|\n/);
  WtI_split.forEach(function(value, index){
    let is_rapid = false;

    if(value.startsWith('_')){
      is_rapid = true;
      value = value.slice(1);
    }

    let hour = Number(value.substring(0,2));
    let min  = Number(value.substring(2,4));

    WtI.push(hour*60+min, is_rapid)
  })


  const MtW_split = MtW_text.split(/,|\n/);
  MtW_split.forEach(function(value, index){
    let is_rapid = false;

    if(value.startsWith('_')){
      is_rapid = true;
      value = value.slice(1);
    }

    let hour = Number(value.substring(0,2));
    let min  = Number(value.substring(2,4));

    MtW.push(hour*60+min, is_rapid)
  })


  const WtM_split = WtM_text.split(/,|\n/);
  WtM_split.forEach(function(value, index){
    let is_rapid = false;

    if(value.startsWith('_')){
      is_rapid = true;
      value = value.slice(1);
    }

    let hour = Number(value.substring(0,2));
    let min  = Number(value.substring(2,4));

    WtM.push(hour*60+min, is_rapid)
  })

  // document.getElementById("test").textContent = WtI.join(" ");
}

function changeLocation(){
  [loc_now, loc_dest] = [loc_dest, loc_now];
  document.getElementById("locations").textContent = loc_now + " to " + loc_dest;
}

function update(){
  let time = new Date();
  let hour = time.getHours();
  let min = time.getMinutes();


  document.getElementById("leave-1").  textContent = hour+":"+min
  document.getElementById("arrive-1"). textContent = "9:10";
  document.getElementById("waiting-1").textContent = "9:10";
  document.getElementById("leave-1"). style.color = white;
  document.getElementById("arrive-1").style.color = "#FF831F";
  document.getElementById("iwade-1").   style.flex = 1;
  document.getElementById("wakayama-1").style.flex = 1;
  document.getElementById("miyamae-1"). style.flex = 1;
}

leave-1
arrive-1
waiting-1