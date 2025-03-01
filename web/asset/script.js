let loc_now  = "Iwade";
let loc_dest = "Miyamae";

let ItW = new Array();
let WtI = new Array();
let MtW = new Array();
let WtM = new Array();


async function load(){
  const ItW_file = await fetch("asset/ItW.csv");
  const WtI_file = await fetch('asset/WtI.csv');
  const MtW_file = await fetch('asset/MtW.csv');
  const WtM_file = await fetch('asset/WtM.csv');

  const ItW_text = await ItW_file.text();
  const WtI_text = await WtI_file.text();
  const MtW_text = await MtW_file.text();
  const WtM_text = await WtM_file.text();

  ItW.push(...ItW_text.trim().split("\n").map(row => row.split(",")));
  WtI.push(...WtI_text.trim().split("\n").map(row => row.split(",")));
  MtW.push(...MtW_text.trim().split("\n").map(row => row.split(",")));
  WtM.push(...WtM_text.trim().split("\n").map(row => row.split(",")));
}

function changeLocation(){
  [loc_now, loc_dest] = [loc_dest, loc_now];
  document.getElementById("locations").textContent = loc_now + " to " + loc_dest;
}

function update(){
  document.getElementById("leave-1").  textContent = "8:10";
  document.getElementById("arrive-1"). textContent = "9:10";
  document.getElementById("waiting-1").textContent = "9:10";
  document.getElementById("leave-1"). style.color = "#FF831F";
  document.getElementById("arrive-1").style.color = "#FF831F";
  document.getElementById("iwade-1").   style.flex = 1;
  document.getElementById("wakayama-1").style.flex = 1;
  document.getElementById("miyamae-1"). style.flex = 1;
}

leave-1
arrive-1
waiting-1