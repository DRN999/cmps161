var width = 750;
var height = 750;	

var size = 10; 
var sample_size = 100; 
var average_size = 1; 
var bump_percent = 0.5;
var outerRadius = height + 130;
var innerRadius = 200;
var interpolation_constant = 10;

var canvas = d3.select('#svg')
	.append('svg')
	.attr('width', width)
	.attr('height', height)
	.attr('border', 1);

function main()
{ // main() 	

	init_input();
	render();
}// End main 

function init_input()
{
	var size_layer_input = document.getElementById('size_layer');
	var sample_size_input = document.getElementById('sample_size');
	var bump_percent_input = document.getElementById('bump_percent');
	var interpolation_constant_input = document.getElementById('interpolation_constant');
	var submit_input = document.getElementById('submit');
	
	submit_input.addEventListener('click' , () => {
		canvas.selectAll('g').remove();
		size = parseInt(size_layer_input.value);
		sample_size = parseInt(sample_size_input.value);
		bump_percent = parseFloat(bump_percent_input.value);
		interpolation_constant = parseInt(interpolation_constant_input.value);
		render();
	});
	
}

function render()
{// renders the cyclic stream graph with the global variables 
	var new_data = create_data(size, sample_size, average_size, bump_percent);
	var keys = get_keys(size);
	new_data.push(cyclic_data(new_data));
	console.log(new_data);
	var interp_data = interpolate_data(size, sample_size + 1, interpolation_constant, new_data);
	interp_data = convert_to_object(interp_data);
	
	console.log(interp_data);
	
	var angle = d3.scaleTime()
		.domain([0, interp_data.length - 1])
		.range([0, 2 * Math.PI]);
			
	var radius = d3.scaleLinear()
		.domain([0, find_max(interp_data) * size])
		.range([innerRadius, outerRadius]);
	
	var z = d3.scaleOrdinal(d3.schemeCategory20)
		.domain(keys);
			
	var stack = d3.stack()
		.keys(keys)
		.offset(d3.stackOffsetSilhouette);
		
	var radial_area = d3.radialArea()
		.angle((d, i) => angle(i))
		.innerRadius((d) => radius(d[0]))
		.outerRadius((d) => radius(d[1]));
		//.curve(d3.curveBasisClosed);
	
	var group = canvas.append('g');
	
	var layer = group.selectAll('.layer')
		.data(stack(interp_data))
		.enter().append('g')
			.attr('class', 'layer')
			.attr('transform', 'translate(' + width/2 + ',' + height/2 + ')');
			
	layer.append('path') 
		.attr('class', 'area')
		.style('fill', (d) => z(d.key))
		.attr('d', radial_area);
	
}// End render 

function cyclic_data(d)
{ // cyclize the data 
	var ret = JSON.parse(JSON.stringify(d[0]));
	ret.time = d.length;
	return ret;
} // End cyclic_data 

function create_data(size, samples, average, bump_p)
{// function that returns the final array structure 
	return d3.range(samples).map((i) => create_random_obj(i, size, average, bump_p));
}// End create_data 

function create_random_obj(index, size, average, bump_p)
{ // function that returns the object with the time and data 
	var push  = '{ "time":' + index + ',';
	var max = 0;
	for(var i = 0; i < size; i++)
	{
		var temp = generate_random(average, bump_p);
		push += '"dat_' + i + '":' + temp + ',';
		if(temp > max)
			max = temp;
		if(i == size - 1)
		{
			push += '"max":' + max + '}';
		}
	}
	return JSON.parse(push);
}// End create_obj



function generate_random(average, bump_p)
{// generates a random number with the bump percentage 
	var val = Math.random() * 2 * average;
	if(Math.random() < bump_p)
		val += Math.random() * (Math.random() * 4) * average;
	return val;
}// End generate_random  

function get_keys(size)
{ // returns the keys of the data 
	return d3.range(size).map((i) => {return 'dat_' + i;});
} // End get_keys 


function find_max(d)
{ // find the max the data structure 
	var max = 0;
	for(var i = 0; i < d.length; i++)
	{
		if(d[i].max > max)
			max = d[i].max;
	}
	return max;
} // End find_max


function interpolate_data(size, sample, constant, data)
{ // interpolates the input data 
	var temp_arr = new Array(size); // converts the object array into a 2d array;
	for(var i = 0; i < size; i++)
	{
		temp_arr[i] = new Array(sample);
	}
	
	for(var i = 0; i < sample; i++)
	{
		var temp = Object.values(data[i]);
		for(var j = 1; j < temp.length - 1; j++)
		{
			temp_arr[j - 1][i] = temp[j];
		}
	}
	
	var temp_interp = new Array(size); // interpolates the data 
	for(var i = 0; i < size; i++) 
	{
		temp_interp[i] = new Array(sample * constant);
	}
	
	for(var i = 0; i < temp_arr.length; i++)
	{
		var thing = d3.interpolateBasisClosed(temp_arr[i]);
		for(var j = 0; j < sample * constant; j++)
		{
			temp_interp[i][j] = thing(j / (sample * constant - 1));
		}
	}
	
	return temp_interp;
	
} // End interpolate_data 


function create_obj(index, data)
{ // creates the object with the input 
	var push  = '{ "time":' + index + ',';
	var max = 0;
	for(var i = 0; i < data.length; i++)
	{
		push += '"dat_' + i + '":' + data[i] + ',';
		if(data[i]> max)
			max = data[i];
		if(i == size - 1)
		{
			push += '"max":' + max + '}';
		}
	}
	return JSON.parse(push);
}// End create_obj

function convert_to_object(data)
{// 
	var temp_arr = d3.transpose(data);
	var ret_arr = new Array();
	for(var i = 0; i < temp_arr.length; i++)
		ret_arr.push(create_obj(i, temp_arr[i]));
	
	return ret_arr;
}
