function varargout = project(varargin)

gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @project_OpeningFcn, ...
                   'gui_OutputFcn',  @project_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end


% --- Executes just before project is made visible.
function project_OpeningFcn(hObject, eventdata, handles, varargin)
handles.output = hObject;


guidata(hObject, handles);
function varargout = project_OutputFcn(hObject, eventdata, handles) 
varargout{1} = handles.output;



function surf_Callback(hObject, eventdata, handles)

function surf_CreateFcn(hObject, eventdata, handles)

if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function dot_x_Callback(hObject, eventdata, handles)
function dot_x_CreateFcn(hObject, eventdata, handles)

if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
function ok_Callback(hObject, eventdata, handles)

surface = get(handles.surf,'string');
x0 = get(handles.dot_x,'string');
y0 = get(handles.dot_y,'string');
z0 = get(handles.dot_z,'string');
syms x;
syms y;
syms z;
syms t;
dx=@(s,x0,y0)subs((subs(diff(s,x),x,x0)),y,y0); %%f'(x0,y0),x)
dy=@(s,x0,y0)subs((subs(diff(s,y),x,x0)),y,y0); %%f'(x0,y0),y)
diff_x = dx(surface,x0,y0);
diff_y = dy(surface,x0,y0);
tangent_func = diff_x*(x-x0)+diff_y*(y-y0)+z0; 
%%z=f'(x0,y0),x)(x-x0)+ f'(x0,y0),y)(y-y0)+z0
x_n = x0+t*diff_x;
y_n = y0+t*diff_y;
z_n = z0-t;
ezsurf(surface);
figure
ezsurf(surface);
hold on
ezsurf(tangent_func);
hold on
ezplot3(x_n, y_n,z_n);
axis equal





function dot_y_Callback(hObject, eventdata, handles)

function dot_y_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function dot_z_Callback(hObject, eventdata, handles)

function dot_z_CreateFcn(hObject, eventdata, handles)

if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on slider movement.
function slider1_Callback(hObject, eventdata, handles)
% hObject    handle to slider1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'Value') returns position of slider
%        get(hObject,'Min') and get(hObject,'Max') to determine range of slider


% --- Executes during object creation, after setting all properties.
function slider1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to slider1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end
